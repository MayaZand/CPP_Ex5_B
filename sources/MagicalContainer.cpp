#include "MagicalContainer.hpp"
#include <algorithm>

using namespace ariel;

void MagicalContainer::addElement(int newElement)
{
	auto it = std::find(elements.begin(), elements.end(), newElement);

	if (it != elements.end())
		return;

	auto to_insert = std::upper_bound(elements.begin(), elements.end(), newElement, [](int a, int b)
									  { return a < b; });
	elements.insert(to_insert, newElement);

	elementsPrime.clear();
	elementsSideCross.clear();
	elementsPrime.reserve(elements.size());
	elementsSideCross.reserve(elements.size());

	for (int &elem : elements)
	{
		if (isPrime(elem))
			elementsPrime.push_back(&elem);
	}

	if (size() == 1)
	{
		int &ret = elements.back();
		elementsSideCross.push_back(&ret);
		return;
	}

	size_t start = 0, end = size() - 1;
	while (start <= end && end != 0)
	{
		int &ret = elements.at(start);
		elementsSideCross.push_back(&ret);

		if (start != end)
		{
			int &ret2 = elements.at(end);
			elementsSideCross.push_back(&ret2);
		}

		start++;
		end--;
	}
}

void MagicalContainer::removeElement(int newElement)
{
	auto it = std::find(elements.begin(), elements.end(), newElement);

	if (it == elements.end())
		throw runtime_error("Element not found kkkk");

	int *ptr = &(*it);

	elements.erase(it);

	if (isPrime(newElement))
	{
		auto it2 = std::find(elementsPrime.begin(), elementsPrime.end(), ptr);
		elementsPrime.erase(it2);
	}

	if (size() == 0)
		return;

	else if (size() == 1)
	{
		int &ret = elements.back();
		elementsSideCross.push_back(&ret);
		return;
	}

	size_t start = 0, end = size() - 1;
	while (start <= end && end != 0)
	{
		int &ret = elements.at(start);
		elementsSideCross.push_back(&ret);

		if (start != end)
		{
			int &ret2 = elements.at(end);
			elementsSideCross.push_back(&ret2);
		}

		start++;
		end--;
	}
}

size_t MagicalContainer::size() const
{
	return this->elements.size();
}

vector<int> &MagicalContainer::getElements()
{
	return this->elements;
}

bool MagicalContainer::isPrime(int num)
{
	if (num < 2)
	{
		return false;
	}

	for (int i = 2; i <= sqrt(num); ++i)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

/********************** Iterators implementation area **********************/

/********************** AscendingIterator **********************/
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
	if (this != &other)
	{
		if (&this->container != &other.container)
			throw runtime_error("Not the same container");

		this->index = other.index;
	}

	return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const Iterator &other) const
{
	const AscendingIterator *ptr = dynamic_cast<const AscendingIterator *>(&other);

	if (ptr == nullptr)
		throw runtime_error("Not the same type!");

	else if (&container != &(ptr->container))
		throw runtime_error("Containers are not the same!");

	return this->index == ptr->index;
}

bool MagicalContainer::AscendingIterator::operator!=(const Iterator &other) const
{
	return !(*this == other);
}

bool MagicalContainer::AscendingIterator::operator>(const Iterator &other) const
{
	const AscendingIterator *ptr = dynamic_cast<const AscendingIterator *>(&other);

	if (ptr == nullptr)
		throw runtime_error("Not the same type!");

	else if (&container != &(ptr->container))
		throw runtime_error("Containers are not the same!");

	return this->index > ptr->index;
}

bool MagicalContainer::AscendingIterator::operator<(const Iterator &other) const
{
	return !(*this > other) && !(*this == other);
}

int MagicalContainer::AscendingIterator::operator*() const
{
	if (index == container.elements.size())
		throw runtime_error("Out of range");

	return container.elements.at(index);
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
	if (index == container.elements.size())
		throw runtime_error("Out of range");

	++index;
	return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
	return AscendingIterator(container, 0);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const
{
	return AscendingIterator(container, container.elements.size());
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
	if (&container != &(other.container))
		throw runtime_error("Containers are not the same!");

	return this->index == other.index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
	return !(*this == other);
}

/********************** SideCrossIterator **********************/
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
	if (this != &other)
	{
		if (&this->container != &other.container)
			throw runtime_error("Not the same container");

		this->index = other.index;
	}

	return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const Iterator &other) const
{
	const SideCrossIterator *ptr = dynamic_cast<const SideCrossIterator *>(&other);

	if (ptr == nullptr)
		throw runtime_error("Not the same type!");

	else if (&container != &(ptr->container))
		throw runtime_error("Containers are not the same!");

	return this->index == ptr->index;
}

bool MagicalContainer::SideCrossIterator::operator!=(const Iterator &other) const
{
	return !(*this == other);
}

bool MagicalContainer::SideCrossIterator::operator>(const Iterator &other) const
{
	const SideCrossIterator *ptr = dynamic_cast<const SideCrossIterator *>(&other);

	if (ptr == nullptr)
		throw runtime_error("Not the same type!");

	else if (&container != &(ptr->container))
		throw runtime_error("Containers are not the same!");

	return this->index > ptr->index;
}

bool MagicalContainer::SideCrossIterator::operator<(const Iterator &other) const
{
	return !(*this > other) && !(*this == other);
}

int MagicalContainer::SideCrossIterator::operator*() const
{
	if (index == container.elementsSideCross.size())
		throw runtime_error("Out of range");

	return *(container.elementsSideCross.at(index));
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{
	if (index == container.elementsSideCross.size())
		throw runtime_error("Out of range");

	++index;
	return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
	return SideCrossIterator(container, 0);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const
{
	return SideCrossIterator(container, container.elementsSideCross.size());
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
	if (&container != &(other.container))
		throw runtime_error("Containers are not the same!");

	return this->index == other.index;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
	return !(*this == other);
}

/********************** PrimeIterator **********************/
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
	if (this != &other)
	{
		if (&this->container != &other.container)
			throw runtime_error("Not the same container");

		this->index = other.index;
	}

	return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const Iterator &other) const
{
	const PrimeIterator *ptr = dynamic_cast<const PrimeIterator *>(&other);

	if (ptr == nullptr)
		throw runtime_error("Not the same type!");

	else if (&container != &(ptr->container))
		throw runtime_error("Containers are not the same!");

	return this->index == ptr->index;
}

bool MagicalContainer::PrimeIterator::operator!=(const Iterator &other) const
{
	return !(*this == other);
}

bool MagicalContainer::PrimeIterator::operator>(const Iterator &other) const
{
	const PrimeIterator *ptr = dynamic_cast<const PrimeIterator *>(&other);

	if (ptr == nullptr)
		throw runtime_error("Not the same type!");

	else if (&container != &(ptr->container))
		throw runtime_error("Containers are not the same!");

	return this->index > ptr->index;
}

bool MagicalContainer::PrimeIterator::operator<(const Iterator &other) const
{
	return !(*this > other) && !(*this == other);
}

int MagicalContainer::PrimeIterator::operator*() const
{
	if (index == container.elementsPrime.size())
		throw runtime_error("Out of range");

	return *(container.elementsPrime.at(index));
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
	if (index == container.elementsPrime.size())
		throw runtime_error("Out of range");

	++index;
	return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
	return PrimeIterator(container, 0);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const
{
	return PrimeIterator(container, container.elementsPrime.size());
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
	if (&container != &(other.container))
		throw runtime_error("Containers are not the same!");

	return this->index == other.index;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
	return !(*this == other);
}