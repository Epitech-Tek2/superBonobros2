/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SoLoader
*/

#ifndef SOLOADER_HPP_
    #define SOLOADER_HPP_
#if _WIN32
    #include <Windows.h>
#else
    #include <dlfcn.h>
#endif
    #include "Error.hpp"

/**
* \brief SoLoader class, load a shared library and get the instance of IGame or IGraphic.
**/
template <typename T>
class SoLoader {
    public:
        SoLoader(const std::string &path)
        {
            this->_path = path;

#if _WIN32
            this->_lib = LoadLibrary(path.c_str());
#else
            this->_lib = dlopen(path.c_str(), RTLD_NOW);
#endif

            if (this->_lib == nullptr)
#if _WIN32
                throw Error("[SoLoader]: Unable to open: " + path + "\n");
#else
                throw Error("[SoLoader]: Unable to open: " + path + "\n" + std::string(dlerror()));
#endif

#if _WIN32
            void *ptr = GetProcAddress((HMODULE)this->_lib, "entry");
#else
            void *ptr = dlsym(this->_lib, "entry");
#endif

            func = reinterpret_cast<T *(*)()>(ptr);
            if (func == nullptr)
                throw Error("[SoLoader]: Unable to find `entry` function in " + path);
        };

        ~SoLoader()
        {
            if (this->_lib != nullptr) {
#if _WIN32
                FreeLibrary((HMODULE)this->_lib);
#else
                dlclose(this->_lib); 
#endif
                this->_lib = nullptr;
            }
        }
        SoLoader(const SoLoader &other) = delete;
        SoLoader &operator =(const SoLoader &other) = delete;

        /**
        * \brief Load the shared library given as parameter, close the old one.
        **/
        T *load(void)
        {
            return func();
        }

    private:
        void *_lib = nullptr;
        std::string _path;
        T *(*func)() = nullptr;
};

#endif