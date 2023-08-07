#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <unordered_map>
#include "Enums.h"
#include "Vector2.h"

#ifndef _BASEINTERFACE_H_
#define _BASEINTERFACE_H_
class BaseInterface
{
private:
    static const char CHAR_NULL{ '\0' };
    static const char CHAR_SPACE{ ' ' };

    std::unordered_map<VectorType, std::shared_ptr<Vector2>> vectors;
    std::vector<std::string> content;

    HorizontalAlignement horizontal;
    VerticalAlignement vertical;

protected:
    size_t calculatePosition(HorizontalAlignement horizontal, size_t container_x, size_t content_x);
    size_t calculatePosition(VerticalAlignement vertical, size_t container_y, size_t content_y);

    void repeatChar(std::ostringstream& sstream, size_t count_repeat, const char* repeated, const char* alter);
    void addToInterface(const std::ostringstream& sstream);
    void updateVectors(const std::ostringstream& sstream);
    void lineConstructor(size_t count_repeat = 0, const char repeated_char = CHAR_NULL, const char start = CHAR_NULL, const char end = CHAR_NULL, const char alter_char = CHAR_NULL, const std::string& additional_string = "", HorizontalAlignement string_position = LEFT);

public:
    std::shared_ptr<Vector2> getVectors(VectorType vec);

    BaseInterface(std::shared_ptr<Vector2> container_size = nullptr, HorizontalAlignement horizontal = LEFT, VerticalAlignement vertical = TOP, size_t offset_x = 0, size_t offset_y = 0);
    ~BaseInterface();

    void createSimpleLine(size_t count_repeat = 0, const char repeated_char = CHAR_NULL, const char start = CHAR_NULL, const char end = CHAR_NULL);
    void createAlteredLine(size_t count_repeat = 0, const char repeated_char = CHAR_NULL, const char alter_char = CHAR_NULL, const char start = CHAR_NULL, const char end = CHAR_NULL);
    void createText(const std::string& additional_string = "", HorizontalAlignement string_position = LEFT);
    void displayInterface() const;
};

#endif // !_BASEINTERFACE_H_

