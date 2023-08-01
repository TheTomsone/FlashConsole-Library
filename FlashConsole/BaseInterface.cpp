#include "BaseInterface.h"

/* TEMP METHOD FOR TESTING */
std::shared_ptr<Vector2> BaseInterface::getVectors(VectorType vec) { return vectors[vec]; }

/* Constructor BaseInterface : Create an new interface */
BaseInterface::BaseInterface(std::shared_ptr<Vector2> container_size, HorizontalAlignement horizontal, VerticalAlignement vertical, size_t offset_x, size_t offset_y) : horizontal{ horizontal }, vertical{ vertical }
{
	vectors.emplace(CONTAINER_SIZE, container_size);
	vectors.emplace(CONTENT_SIZE, new Vector2{});
	vectors.emplace(POSITION, new Vector2{ calculatePosition(horizontal, vectors[CONTAINER_SIZE]->getX(), vectors[CONTENT_SIZE]->getX()),
											calculatePosition(vertical, vectors[CONTAINER_SIZE]->getY(), vectors[CONTENT_SIZE]->getY()) });
	vectors[POSITION]->setOffset(offset_x, offset_y);
	for (size_t increment_y{ 0 }; increment_y < vectors[CONTAINER_SIZE]->getY(); increment_y++)
	{
		std::string line{};
		line.append(vectors[CONTAINER_SIZE]->getX(), CHAR_SPACE);
		content.push_back(line);
	}
}
/* Destructor BaseInterface : Destroy the interface */
BaseInterface::~BaseInterface() {}


// PROTECTED METHODS
/* Calculate Horizontal Position */
size_t BaseInterface::calculatePosition(HorizontalAlignement horizontal, size_t container_x, size_t content_x)
{
	return horizontal == CENTER_H ? container_x / 2 - content_x / 2 : horizontal == RIGHT ? container_x - content_x : 0;
}
/* Calculate Vertical Position */
size_t BaseInterface::calculatePosition(VerticalAlignement vertical, size_t container_y, size_t content_y)
{
	return vertical == CENTER_V ? container_y / 2 - content_y / 2 : vertical == BOTTOM ? container_y - content_y : 0;
}
/* Repeat a character in a String Stream a specified number of time */
void BaseInterface::repeatChar(std::ostringstream& sstream, size_t count_repeat, const char* repeated, const char* alter)
{
	if (repeated)
		for (size_t increment{ 0 }; increment < count_repeat; increment++)
			if (alter)
				sstream << (increment % 2 == 0 ? *repeated : *alter);
			else
				sstream << *repeated;

}
/* Update Vectors in interface with a generated String Stream */
void BaseInterface::updateVectors(const std::ostringstream& sstream)
{
	size_t text_size{ sstream.str().size() };
	Vector2 correction{ text_size, 0 };
	*vectors[CONTENT_SIZE] += correction;
	*vectors[POSITION] = Vector2(calculatePosition(horizontal, vectors[CONTAINER_SIZE]->getX(), vectors[CONTENT_SIZE]->getX()), calculatePosition(vertical, vectors[CONTAINER_SIZE]->getY(), vectors[CONTENT_SIZE]->getY()));
}
/* Add String Stream in the Content vector */
void BaseInterface::addToInterface(const std::ostringstream& sstream)
{
	content.at(vectors[POSITION]->getY()).replace(vectors[POSITION]->getX(), vectors[CONTENT_SIZE]->getX(), sstream.str());
}

// PUBLIC METHODS
/* Generate a new line in the interface*/
void BaseInterface::lineConstructor(size_t half_count_repeat, const char repeated_char, const char start_char, const char end_char, const char alter_char, const std::string& additional_string, HorizontalAlignement string_position)
{
	std::ostringstream overlay;

	const char* start = (start_char == CHAR_NULL ? nullptr : &start_char);
	const char* end = (end_char == CHAR_NULL ? nullptr : &end_char);
	const char* repeated = (repeated_char == CHAR_NULL ? nullptr : &repeated_char);
	const char* alter = (alter_char == CHAR_NULL ? nullptr : &alter_char);

	if (start)
		overlay << *start;

	if (string_position == LEFT)
		overlay << additional_string;

	repeatChar(overlay, half_count_repeat, repeated, alter);

	if (string_position == CENTER_H)
		overlay << additional_string;

	repeatChar(overlay, half_count_repeat, repeated, alter);

	if (string_position == RIGHT)
		overlay << additional_string;

	if (end)
		overlay << *end;

	updateVectors(overlay);
	addToInterface(overlay);
}
/* Display the interface */
void BaseInterface::displayInterface() const
{
	for (std::string const line : content)
		std::cout << line << std::endl;
}