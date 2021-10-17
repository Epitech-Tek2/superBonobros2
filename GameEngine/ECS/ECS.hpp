/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** ECS
*/

#ifndef ECS_HPP_
#define ECS_HPP_

#include <vector>
#include <map>
#include <algorithm>
#include "TypeIndexer.hpp"
#include "AEntity.hpp"
#include "ASystem.hpp"
#include "SoLoader.hpp"
#include <iostream>

namespace gameEngine {

    class AScene;

    class ECS {
        public:
            ECS(AScene *scene);
            ~ECS();

            void update(float deltaTime);

            AScene *getScene(void) const;
            void registerEntity(std::shared_ptr<AEntity> entity)
            {
                if (std::find(_entitys.begin(), _entitys.end(), entity) == _entitys.end())
                    _entitys.push_back(entity);
            }

            template<typename T>
            T &getEntityComponent(std::shared_ptr<AEntity> entity)
            {
                auto ptr = entity->getComponent(getComponentIndex<T>());
                if (ptr == nullptr)
                    throw ("Component not found\n");
                return (static_cast<T&>(*ptr.get()));
            }

            template<typename T>
            T &getEntityComponent(const AEntity *entity)
            {
                return getEntityComponent<T>(findSharedPtr(_entitys, entity));
            }


            template<typename T>
            std::size_t getComponentIndex(void)
            {
                return _componentIndexer.getIndexOf<T>();
            }

            template<typename T, typename ...Targs>
            std::shared_ptr<T> addEntity(Targs&& ...args)
            {
                T* entity(new T(this));
                std::shared_ptr<T> uPtr(entity);
                _entitys.emplace_back(uPtr);
                uPtr->init(this, std::forward<Targs>(args)...);

                return uPtr;
            }

            template<typename T, typename ...Targs>
            std::shared_ptr<T> addSystem(Targs&& ...args)
            {
                T* system(new T(this));
                std::shared_ptr<T> uPtr(system);
                _systems.emplace_back(uPtr);
                uPtr->init(this, std::forward<Targs>(args)...);

                return uPtr;
            }

            void delSystem(const std::shared_ptr<ASystem> system)
            {
                delSharedPtr(_systems, system);
            }

            template<typename ...TArgs>
            void systemAddDependances(std::shared_ptr<ASystem> system)
            {
                setDependancesHelper<TArgs...>(system, true);

                for (auto entity : _entitys) {
                    system->mayAddEntity(entity);
                    system->mayDelEntity(entity);
                }
            }

            template<typename ...TArgs>
            void systemAddDependances(const ASystem *system)
            {
                systemAddDependances<TArgs...>(findSharedPtr(_systems, system));
            }

            template<typename ...TArgs>
            void systemDelDependances(std::shared_ptr<ASystem> system)
            {
                setDependancesHelper<TArgs...>(system, false);

                for (auto entity : _entitys)
                    system->mayDelEntity(entity);
            }

            template<typename ...TArgs>
            void addComponents(std::shared_ptr<AEntity> entity, TArgs ...args)
            {
                addComponentsHelper(entity, args...);
                for (auto system : _systems) {
                    system->mayAddEntity(entity);
                    system->mayDelEntity(entity);
                }
            }

            template<typename ...TArgs>
            void addComponents(const AEntity *entity, TArgs ...args)
            {
                addComponents(findSharedPtr(_entitys, entity), args...);
            }

            template<typename ...TArgs>
            void delComponents(std::shared_ptr<AEntity> entity)
            {
                delComponentsHelper<TArgs...>(entity);
                for (auto system : _systems)
                    system->mayDelEntity(entity);
            }

        protected:
        private:
            AScene *_scene;
            std::vector<std::shared_ptr<AEntity>> _entitys;
            std::vector<std::shared_ptr<ASystem>> _systems;
            std::vector<std::shared_ptr<Component>> _components;
            InheritenceTypeIndexer<Component> _componentIndexer;
            std::map<std::string, std::tuple<std::shared_ptr<SoLoader<AEntity>>, size_t>> _dynamicLoader;

            void delEntity(const std::shared_ptr<AEntity> entity);
            void unloadEntity(const std::string &library);
            void removeDeadEntitys(void);

            template<typename T>
            void addComponentsHelper(std::shared_ptr<AEntity> entity, T component)
            {
                T* comp(new T(component));
                std::shared_ptr<Component> uPtr(comp);
                _components.emplace_back(uPtr);

                uPtr->_entity = entity;
                auto index = getComponentIndex<T>();
                auto oldComp = entity->getComponent(index);
                if (oldComp)
                    delSharedPtr(_components, oldComp);
                entity->addComponent(index, uPtr);
            }

            template <typename T, typename ...Rest>
            void addComponentsHelper(std::shared_ptr<AEntity> entity, T Component, Rest ...rest)
            {
                addComponentsHelper(entity, Component);
                addComponentsHelper(entity, rest...);
            }

            template<typename T>
            void delComponentsHelper(std::shared_ptr<AEntity> entity)
            {
                auto comp = entity->getComponent(getComponentIndex<T>());

                if (comp) {
                    entity->delComponent(getComponentIndex<T>());
                    delSharedPtr(_components, comp);
                }
            }

            template <typename T, typename T2, typename ...Rest>
            void delComponentsHelper(std::shared_ptr<AEntity> entity)
            {
                delComponentsHelper<T>(entity);
                delComponentsHelper<T2, Rest...>(entity);
            }

            template <typename T>
            void setDependancesHelper(std::shared_ptr<ASystem> system, bool state)
            {
                system->signatureSetBit(getComponentIndex<T>(), state);
            }

            template <typename T, typename T2, typename ...Rest>
            void setDependancesHelper(std::shared_ptr<ASystem> system, bool state)
            {
                setDependancesHelper<T>(system, state);
                setDependancesHelper<T2, Rest...>(system, state);
            }

            template <typename T>
            void delSharedPtr(std::vector<std::shared_ptr<T>> &vec, const std::shared_ptr<T> ptr)
            {
                auto it = std::find_if(vec.begin(), vec.end(), [&](std::shared_ptr<T>& p)
                {
                    return p == ptr;
                });
                if (it != vec.end())
                {
                    vec.erase(it);
                }
            }

            template <typename T>
            std::shared_ptr<T> findSharedPtr(std::vector<std::shared_ptr<T>> &vec, const T *ptr)
            {
                auto it = std::find_if(vec.begin(), vec.end(), [&](std::shared_ptr<T>& p)
                {
                    return p.get() == ptr;
                });
                if (it != vec.end())
                {
                    return *it;
                }
                throw ("Pointer not stcked\n");
            }
    };

};

#endif /* !ECS_HPP_ */
