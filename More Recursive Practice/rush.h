#ifndef CAR_H
#define CAR_H
class car {
public:
 car(); 
 ~car();
 car(const car& src);
 car& operator= (const car& src);

 int size; 
 char orientation; 
 int rowTop;
 int colFront; 
 int rowBottom; 
 int colBack; 
};

#endif
 
car::car()
  {
   size =0 ; 
   orientation =0; 
   rowTop = 0;
   colFront = 0 ; 
   rowBottom = 0 ; 
   colBack =0 ; 
  }
car::~car()
 {}
car:: car(const car& src)
{}
 car& car::operator= (const car& src)
{}
