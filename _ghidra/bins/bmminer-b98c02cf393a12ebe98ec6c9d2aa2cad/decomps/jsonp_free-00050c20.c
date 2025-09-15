
void jsonp_free(int param_1)

{
  if (param_1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00050c2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*do_free)();
    return;
  }
  return;
}

