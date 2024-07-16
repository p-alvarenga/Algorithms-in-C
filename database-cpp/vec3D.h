#ifndef VEC3D_H
#define VEC3D_H

class Vec3D : Vec2D
{
    private:
        double _k;

    public: 

    Vec3D operator+(Vec3D _v3D) const 
    {
        return Vec3D(this -> _i + _v3D.i(),
                     this -> _j + _v3D.j(),
                     this -> _z + _v3D.k()); 
    }

    Vec3D operator+(Vec2D _v2D) const
    {
        return Vec3D(this -> _i + _v2D.i(),
                     this -> _j + _v2D.j(), 
                     0); 
    }

    void setVec(double _i, double _j, double _z) override
    {
        this -> _i = _i;
        this -> _j = _j;
        this -> _z = _z;
    
        return;
    }
 
    virtual inline double mod() { return (sqrt(double(i*i + j*j + z*z)); }

    inline double i() { return this -> _i; }
    inline double j() { return this -> _j; }
    inline double k() { return this -> _k; }


    Vec3D(double _i = 0, double _j = 0, double _z = 0): i(_i), j(_j), z(_z) { }
};


