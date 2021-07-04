unsigned int getAbs(int n)
{
  unsigned int ans = 0;
  for(int i = 0; i < 32; i++){
    if(!(n & (1 << i))){
      ans += (1 << i);
    }
  }
  return ans + 1;
}
