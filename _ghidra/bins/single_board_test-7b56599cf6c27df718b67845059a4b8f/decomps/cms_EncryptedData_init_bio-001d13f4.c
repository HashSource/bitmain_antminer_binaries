
void cms_EncryptedData_init_bio(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 4);
  if ((*(int *)(puVar1[1] + 0xc) != 0) && (puVar1[2] != 0)) {
    *puVar1 = 2;
  }
  cms_EncryptedContent_init_bio();
  return;
}

