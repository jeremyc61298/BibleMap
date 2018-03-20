#include <vector>
#include <stdexcept>

namespace util
{
	template <typename KeyType, typename ValueType>
	class Map
	{

	public:
		// Wrapper is an inner class of the Map Template
		class Wrapper
		{
		public:
			//this is a type cast operator that can be used to cast an object
			//of type Wrapper to an object of type ValueType
			operator ValueType&();
			ValueType* operator &();
			const ValueType& operator =(const ValueType& rValue);

		private:
			Wrapper(Map &map, const KeyType &key);
			Wrapper(const Wrapper & value);
			Map& map;
			KeyType key;
			ValueType* value;

			friend class Map;
		};

		Wrapper operator[](const KeyType& key);
		unsigned size();

		class Iterator
		{
		public:
			virtual ~Iterator();
			Iterator operator++(int junk);
			Iterator operator++();
			Iterator operator--(int junk);
			Iterator operator--();
			ValueType& operator*();

		private:
			Iterator(Map& map);

			Map& map;
			KeyType index;

			//friend class Map;
		};

		Iterator getIterator(KeyType start) const;

	private: 
		std::vector<KeyType> keys;
		std::vector<ValueType> values;

		ValueType* find(const KeyType &key);

	protected:
		ValueType* set(const KeyType &key, const ValueType &value);
	};

	/*==========================================================================
	* Map class methods
	*/

	template <typename KeyType, typename ValueType>
	typename Map<KeyType, ValueType>::Wrapper Map<KeyType, ValueType>::operator[](const KeyType& key)
	{
		return Wrapper(*this, key);
	}

	template <typename KeyType, typename ValueType>
	unsigned Map<KeyType, ValueType>::size()
	{
		//return the number of items that are in the keys or values list
		return keys.size();
	}

	template <typename KeyType, typename ValueType>
	ValueType* Map<KeyType, ValueType>::find(const KeyType &key)
	{
		ValueType* result = NULL;

		for (int i = 0; i < keys.size(); i++)
		{
			if (keys[i] == key)
			{
				result = &(values[i]);
			}
		}
		return result;
	}

	template <typename KeyType, typename ValueType>
	ValueType* Map<KeyType, ValueType>::set(const KeyType &key, const ValueType &value)
	{
		ValueType* result = find(key);
		if (result != NULL)
		{
			*result = value;
		}
		else
		{
			keys.push_back(key);
			values.push_back(value);
			result = find(key);
		}
		return result;
	}

	template<typename KeyType, typename ValueType>
	typename Map<KeyType, ValueType>::Iterator Map<KeyType, ValueType>::getIterator(KeyType start) const
	{
		if (find(start) == NULL)
		{
			throw std::range_error("Key not found in map.");
		}
		Iterator i(*this);
		i.index = start;
		return i;
	}

	/*==========================================================================
	* Wrapper methods
	*/

	template <typename KeyType, typename ValueType>
	Map<KeyType, ValueType>::Wrapper::Wrapper(Map &map, const KeyType &key) :
		map(map), key(key)
	{
		value = map.find(key);
	}

	//Copy constructor
	template <typename KeyType, typename ValueType>
	Map<KeyType, ValueType>::Wrapper::Wrapper(const Wrapper& rValue) :
		map(rValue.map), key(rValue.key), value(rValue.value)
	{}

	//conversion operator, from a Wrapper to a ValueType
	template <typename KeyType, typename ValueType>
	Map<KeyType, ValueType>::Wrapper::operator ValueType&()
	{
		if (value == NULL)
		{
			throw std::range_error("Key not found in map");
		}
		return *value;
	}

	//address of operator. This is used when the programmer tries to 
	//find the address of a Wrapper object.  We return the address of the
	//value inside the wrapper instead.
	template <typename KeyType, typename ValueType>
	ValueType* Map<KeyType, ValueType>::Wrapper::operator &()
	{
		if (value == NULL)
		{
			throw std::range_error("Key not found in map");
		}
		return value;
	}

	//assignment operator.  This is used when a wrapper is the l-value in an assignment 
	//and the r-value is of type ValueType
	template <typename KeyType, typename ValueType>
	const ValueType& Map<KeyType, ValueType>::Wrapper::operator =(const ValueType& rValue)
	{
		map.set(key, rValue);
		return rValue;
	}

	/*==========================================================================
	* Iterator Methods
	*/

	template <typename KeyType, typename ValueType>
	Map<KeyType, ValueType>::Iterator::Iterator(Map& map)
		: map(map)
	{}

	template <typename KeyType, typename ValueType>
	Map<KeyType, ValueType>::Iterator::~Iterator()
	{}

	template<typename KeyType, typename ValueType>
	typename Map<KeyType, ValueType>::Iterator Map<KeyType, ValueType>::Iterator::operator++(int junk)
	{
		return Iterator();
	}

	template<typename KeyType, typename ValueType>
	typename Map<KeyType, ValueType>::Iterator Map<KeyType, ValueType>::Iterator::operator++()
	{
		return Iterator();
	}

	template<typename KeyType, typename ValueType>
	typename Map<KeyType, ValueType>::Iterator Map<KeyType, ValueType>::Iterator::operator--(int junk)
	{
		return Iterator();
	}

	template<typename KeyType, typename ValueType>
	typename Map<KeyType, ValueType>::Iterator Map<KeyType, ValueType>::Iterator::operator--()
	{
		return Iterator();
	}

	template<typename KeyType, typename ValueType>
	ValueType& Map<KeyType, ValueType>::Iterator::operator*()
	{
		return &map[index];
	}

}



