class Vec2D
{
    private:
        double _i, _j;

    public: 
        virtual void setVec(double _i = 0, double _j = 0)
        {
            this -> _i = _i;
            this -> _j = _j;

            return;
        }
    
        Vec2D operator+(const Vec2D& v2D) const 
        { 
            return Vec2D(this -> _i + v2D.i(), this -> _j + v2D.j()); 
        }
         
        Vec2D operator-(const Vec2D& _v2D) const 
        { 
            return Vec2D(this -> _i - v2D.i(), this -> _j - v2D.j()); 
        }

        virtual inline double mod() { return (sqrt(double(i*i + j*j)); }

        inline double i() { return this -> _i; }
        inline double j() { return this -> _j; }

                    
        Vec2D(double _i = 0, double _j = 0): i(_i), j(_j) { }
};
