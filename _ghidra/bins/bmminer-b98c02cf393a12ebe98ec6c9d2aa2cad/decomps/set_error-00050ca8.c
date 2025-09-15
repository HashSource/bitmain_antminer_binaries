
void set_error(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_4;
  
  uStack_4 = param_4;
  jsonp_error_vset(*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x18),
                   *(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x20),param_3,&uStack_4
                  );
  jsonp_error_set_source(*(undefined4 *)(param_1 + 0x38),param_2);
  return;
}

