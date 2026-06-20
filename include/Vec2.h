#pragma once

struct Vec2
{
	Vec2(float x = 0, float y = 0)
	    : mX(x)
		, mY(y) 
	{
	}

    float mX;
    float mY;

    // 演算子オーバーロード
    Vec2 operator+(const Vec2& other) const
    {
        return Vec2(mX + other.mX, mY + other.mY);
    }

    Vec2 operator-(const Vec2& other) const
    {
        return Vec2(mX - other.mX, mY - other.mY);
    }

    Vec2 operator*(float scalar) const
    {
        return Vec2(mX * scalar, mY * scalar);
    }

	Vec2 operator/(float scalar) const
	{
		return Vec2(mX / scalar, mY / scalar);
	}

    Vec2& operator+=(const Vec2& other)
    {
        mX += other.mX;
        mY += other.mY;
        return *this;
    }

    Vec2& operator-=(const Vec2& other)
    {
        mX -= other.mX;
        mY -= other.mY;
        return *this;
    }
    
    bool operator==(const Vec2& other) const
    {
        return mX == other.mX && mY == other.mY;
    }

    bool operator!=(const Vec2& other) const
    {
        return !(*this == other);
    }
};