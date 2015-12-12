#pragma once

class COrganism;

class CBehaviour
{
  private:
    
  public:
    CBehaviour() = default;
    ~CBehaviour() = default;

    virtual void perform( double deltaTime, COrganism* self ) = 0;
    virtual CBehaviour* newCopy() const = 0;
};
