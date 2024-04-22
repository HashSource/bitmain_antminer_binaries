
void Sha256_Onestep(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined auStack_70 [104];
  
  Sha256_Init(auStack_70);
  Sha256_Update(auStack_70,param_1,param_2);
  Sha256_Final(auStack_70,param_3);
  return;
}

