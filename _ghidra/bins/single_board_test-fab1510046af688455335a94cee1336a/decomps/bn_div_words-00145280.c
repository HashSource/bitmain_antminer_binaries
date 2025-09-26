
ulong bn_div_words(ulong h,ulong l,ulong d)

{
  ulong uVar1;
  
  uVar1 = __aeabi_uldivmod(l,h,d,0);
  return uVar1;
}

