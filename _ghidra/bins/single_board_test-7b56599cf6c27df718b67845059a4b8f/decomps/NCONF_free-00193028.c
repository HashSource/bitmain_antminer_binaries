
void NCONF_free(CONF *conf)

{
  if (conf != (CONF *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0019302e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*conf->meth->destroy)(conf);
    return;
  }
  return;
}

