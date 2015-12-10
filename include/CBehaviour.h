#pragma once

class COrganism;

class CBehaviour
{
  private:
    
  public:
    CBehaviour() = default;
    ~CBehaviour() = default;

    virtual void perform( COrganism* self ) = 0;
};
