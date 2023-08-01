#include "Vector2.h"

// GETTERS & SETTERS
size_t Vector2::getX() const { return base_x + offset_x; }
size_t Vector2::getY() const { return base_y + offset_y; }
void Vector2::setVector(size_t new_base_x, size_t new_base_y) { base_x = new_base_x; base_y = new_base_y; }
void Vector2::setOffset(size_t new_offset_x, size_t new_offset_y) { offset_x = new_offset_x; offset_y = new_offset_y; }

// CONSTRUCTORS / DESTRUCTOR
Vector2::Vector2(size_t base_x, size_t base_y, size_t offset_x, size_t offset_y) : base_x{ base_x }, base_y{ base_y }, offset_x{ offset_x }, offset_y{ offset_y } {}
Vector2::Vector2(const Vector2& source) : base_x{ source.base_x }, base_y{ source.base_y }, offset_x{ source.offset_x }, offset_y{ source.offset_y } {}
Vector2::~Vector2() {}

// OPERATOR OVERLOADS
bool Vector2::operator==(const Vector2& other) const { return base_x == other.base_x && base_y == other.base_y && offset_x == other.offset_x && offset_y == other.offset_y; }
bool Vector2::operator!=(const Vector2& other) const { return base_x != other.base_x && base_y != other.base_y && offset_x != other.offset_x && offset_y != other.offset_y; }
Vector2 Vector2::operator+(const Vector2& rhs) { return Vector2(this->getX() + rhs.getX(), this->getY() + rhs.getY()); }
Vector2& Vector2::operator+=(const Vector2& rhs) { this->setVector(this->getX() + rhs.getX(), this->getY() + rhs.getY()); return *this; }
Vector2 Vector2::operator-(const Vector2& rhs) { return Vector2(this->getX() - rhs.getX(), this->getY() - rhs.getY()); }
Vector2& Vector2::operator-=(const Vector2& rhs) { this->setVector(this->getX() - rhs.getX(), this->getY() - rhs.getY()); return *this; }