#include "MagicalContainer.hpp"
#include <algorithm>

using namespace ariel;

void MagicalContainer::addElement(int newElement)
{
	auto it = std::find(elements.begin(), elements.end(), newElement);

	if (it == elements.end())
		return;
	
	elements.push_back(newElement);
}

void MagicalContainer::removeElement(int index)
{
	// if (index < 0 || index >= this->elements.size())
	// {
	//     throw invalid_argument ("Invalid index!");

	//     return;
	// }

	// elements.erase(elements.begin() + index);
}

size_t MagicalContainer::size() const
{
	return this->elements.size();
}

vector<int> &MagicalContainer::getElements()
{
	return this->elements;
}

bool isPrime(int num)
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
	if (index == container.elementsAscend.size())
		throw runtime_error("Out of range");
	
	return *(container.elementsAscend.at(index));
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
	if (index == container.elementsAscend.size())
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
	return AscendingIterator(container, container.elementsAscend.size());
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const {
	if (&container != &(other.container))
		throw runtime_error("Containers are not the same!");

	return this->index == other.index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const {
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

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const {
	if (&container != &(other.container))
		throw runtime_error("Containers are not the same!");

	return this->index == other.index;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const {
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

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const {
	if (&container != &(other.container))
		throw runtime_error("Containers are not the same!");

	return this->index == other.index;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const {
	return !(*this == other);
}