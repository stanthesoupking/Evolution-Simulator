#pragma once

class CColor
{
  private:
    
  public:
    int r, g, b;
    CColor( int _r, int _g, int _b ): 
	    r(_r), 
        g(_g), 
        b(_b) {}
    ~CColor() = default;
};
