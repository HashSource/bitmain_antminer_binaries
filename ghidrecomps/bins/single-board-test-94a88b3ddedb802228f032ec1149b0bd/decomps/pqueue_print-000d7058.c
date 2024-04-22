
void pqueue_print(pqueue pq)

{
  byte *pbVar1;
  
  for (pbVar1 = *(byte **)pq; pbVar1 != (byte *)0x0; pbVar1 = *(byte **)(pbVar1 + 0xc)) {
    printf(DAT_000d708c,(uint)*pbVar1,(uint)pbVar1[1],(uint)pbVar1[2],(uint)pbVar1[3],
           (uint)pbVar1[4],(uint)pbVar1[5],(uint)pbVar1[6],(uint)pbVar1[7]);
  }
  return;
}

