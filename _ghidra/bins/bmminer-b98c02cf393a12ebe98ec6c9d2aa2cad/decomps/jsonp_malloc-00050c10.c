
void jsonp_malloc(int param_1)

{
  if (param_1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00050c1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*do_malloc)();
    return;
  }
  return;
}

