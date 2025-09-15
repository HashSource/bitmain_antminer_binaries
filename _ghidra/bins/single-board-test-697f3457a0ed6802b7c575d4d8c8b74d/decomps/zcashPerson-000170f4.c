
void zcashPerson(uint8_t *person,int n,int k)

{
  int k_local;
  int n_local;
  uint8_t *person_local;
  
  memcpy(person,"ZcashPoW",8);
  *(int *)(person + 8) = n;
  *(int *)(person + 0xc) = k;
  return;
}

