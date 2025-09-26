
void cmac_key_free(int param_1)

{
  if (*(CMAC_CTX **)(param_1 + 0x14) != (CMAC_CTX *)0x0) {
    CMAC_CTX_free(*(CMAC_CTX **)(param_1 + 0x14));
    return;
  }
  return;
}

