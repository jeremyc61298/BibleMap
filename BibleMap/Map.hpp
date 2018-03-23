
#include <vector>
#include <stdexcept>

namespace util
{
	template <typename KeyType, typename ValueType>
	class Map
	{

	public:
		virtual ~Map();

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
			void operator++(int junk);
			void operator++();
			void operator--(int junk);
			void operator--();
			ValueType& operator*();

		private:
			Iterator(Map& map, int index);

			Map& map;
			int index;

			friend class Map;
		};

		Iterator getIterator(const KeyType start);

		class IVisitor
		{
		public:
			IVisitor();
			virtual ~IVisitor();

			virtual void visit(KeyType& key, ValueType& value) = 0;

		private:

		};

		void visit(IVisitor& visitor);
	private: 
		std::vector<KeyType> keys;
		std::vector<ValueType> values;

		ValueType* find(const KeyType &key);
		int findIndex(const KeyType &key);

	protected:
		ValueType* set(const KeyType &key, const ValueType &value);
	};

	/*==========================================================================
	* Map class methods
	*/

	template <typename KeyType, typename ValueType>
	Map<KeyType, ValueType>::~Map()
	{
	}

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
	int Map<KeyType, ValueType>::findIndex(const KeyType &key)
	{
		int result = -1;

		for (int i = 0; i < keys.size(); i++)
		{
			if (keys[i] == key)
			{
				result = i;
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
	typename Map<KeyType, ValueType>::Iterator Map<KeyType, ValueType>::getIterator(const KeyType start) 
	{
		int indexTemp = findIndex(start);
		if (indexTemp == -1)
		{
			throw std::range_error("Key not found in map.");
		}
		Iterator i(*this, indexTemp);
		return i;
	}

	template<typename KeyType, typename ValueType>
	void Map<KeyType, ValueType>::visit(IVisitor& visitor)
	{
		for (int i = 0; i < keys.size(); i++)
		{
			visitor.visit(keys[i], values[i]);
		}
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
	Map<KeyType, ValueType>::Iterator::Iterator(Map& map, int index)
		: map(map), index(index)
	{}

	template <typename KeyType, typename ValueType>
	Map<KeyType, ValueType>::Iterator::~Iterator()
	{}

	template<typename KeyType, typename ValueType>
	void Map<KeyType, ValueType>::Iterator::operator++(int junk)
	{
		index++;
		if (index == map.keys.size())
		{
			index = 0;
		}
	}

	template<typename KeyType, typename ValueType>
	void Map<KeyType, ValueType>::Iterator::operator++()
	{
		++index;
		if (index == map.keys.size())
		{
			index = 0;
		}
	}

	template<typename KeyType, typename ValueType>
	void Map<KeyType, ValueType>::Iterator::operator--(int junk)
	{
		index--;
		if (index == -1)
		{
			index = map.keys.size() - 1;
		}
	}

	template<typename KeyType, typename ValueType>
	void Map<KeyType, ValueType>::Iterator::operator--()
	{
		--index;
		if (index == -1)
		{
			index = map.keys.size() - 1;
		}
	}

	template<typename KeyType, typename ValueType>
	ValueType& Map<KeyType, ValueType>::Iterator::operator*()
	{
		return map.values[index];
	}

	/*==========================================================================
	* IVisitor class methods
	*/

	template <typename KeyType, typename ValueType>
	Map<KeyType, ValueType>::IVisitor::IVisitor()
	{}

	template <typename KeyType, typename ValueType>
	Map<KeyType, ValueType>::IVisitor::~IVisitor()
	{}

}