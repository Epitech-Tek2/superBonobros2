/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** TypeIndexer
*/

#ifndef TYPEINDEXER_HPP_
#define TYPEINDEXER_HPP_

#include <typeindex>
#include <unordered_map>

using IndexType = std::size_t;

class TypeIndexer {

    public :
        TypeIndexer() = default;
        ~TypeIndexer() = default;

        template <typename T>
        IndexType getIndexOf()
        {
            std::type_index type = typeid(T);

            for (auto it : _typeIdList)
                if (it.first == type)
                    return it.second;
            _typeIdList.emplace(type, getIndex());
            return _typeIdList[type];
        }

    private :
        std::unordered_map<std::type_index, IndexType> _typeIdList;
        IndexType _index = 0;

        IndexType getIndex(void) {
            return _index++;
        };
};

template <typename O>
class InheritenceTypeIndexer : virtual public TypeIndexer {

    public :
        InheritenceTypeIndexer() = default;
        ~InheritenceTypeIndexer() = default;

        template <typename T>
        IndexType getIndexOf()
        {
            if (!std::is_base_of<O, T>::value)
                throw ("Type T must be base of Type O");
            return TypeIndexer::getIndexOf<T>();
        }
};

#endif /* !TYPEINDEXER_HPP_ */
