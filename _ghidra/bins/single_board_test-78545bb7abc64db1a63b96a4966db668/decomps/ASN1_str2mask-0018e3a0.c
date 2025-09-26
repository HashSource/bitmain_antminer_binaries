
void ASN1_str2mask(char *param_1,undefined4 *param_2)

{
  *param_2 = 0;
  CONF_parse_list(param_1,0x7c,1,(list_cb *)0x18dea9,param_2);
  return;
}

