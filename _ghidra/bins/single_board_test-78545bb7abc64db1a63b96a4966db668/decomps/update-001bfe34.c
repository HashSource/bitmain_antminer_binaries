
void update(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = EVP_MD_CTX_md_data();
  MDC2_Update(uVar1,param_2,param_3,param_4);
  return;
}

