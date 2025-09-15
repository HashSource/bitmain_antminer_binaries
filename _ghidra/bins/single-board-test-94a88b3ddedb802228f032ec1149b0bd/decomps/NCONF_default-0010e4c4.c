
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CONF_METHOD * NCONF_default(void)

{
  return (CONF_METHOD *)&default_method;
}

