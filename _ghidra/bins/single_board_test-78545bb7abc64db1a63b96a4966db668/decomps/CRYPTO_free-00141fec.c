
void CRYPTO_free(void *ptr)

{
  if (free_impl == (code *)(undefined *)0x141fed || free_impl == (code *)0x0) {
    (*(code *)(undefined *)0x0)(ptr);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00142006. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*free_impl)();
  return;
}

