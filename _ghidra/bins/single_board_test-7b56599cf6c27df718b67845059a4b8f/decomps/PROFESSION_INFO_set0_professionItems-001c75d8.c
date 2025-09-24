
void PROFESSION_INFO_set0_professionItems
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  OPENSSL_sk_pop_free(*(undefined4 *)(param_1 + 4),0x106041,0x81c,&_GLOBAL_OFFSET_TABLE_,param_4);
  *(undefined4 *)(param_1 + 4) = param_2;
  return;
}

