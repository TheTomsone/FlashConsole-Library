#ifndef _VECTOR2_H_
#define _VECTOR2_H_

class Vector2
{
private:
    size_t base_x;
    size_t base_y;
    size_t offset_x;
    size_t offset_y;

public:
    // GETTERS & SETTERS
    size_t getX() const;
    size_t getY() const;
    void setVector(size_t new_base_x, size_t new_base_y);
    void setOffset(size_t new_offset_x, size_t new_offset_y);

    // CONSTRUCTORS / DESTRUCTOR
    Vector2(size_t base_x = 0, size_t base_y = 0, size_t offset_x = 0, size_t offset_y = 0);
    Vector2(const Vector2& source);
    ~Vector2();

    // OPERATOR OVERLOADS
    bool operator==(const Vector2& other) const;
    bool operator!=(const Vector2& other) const;
    Vector2 operator+(const Vector2& rhs);
    Vector2& operator+=(const Vector2& rhs);
    Vector2 operator-(const Vector2& rhs);
    Vector2& operator-=(const Vector2& rhs);
};

#endif // !_VECTOR2_H_
