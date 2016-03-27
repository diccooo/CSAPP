int any_even_one(unsigned x){
  unsigned mask = 0x55555555;
  return (x | mask) == 0xFFFFFFFF;
}
