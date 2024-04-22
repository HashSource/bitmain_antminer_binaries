
void dh_copy_parameters(int param_1,int param_2)

{
  int_dh_param_copy(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_2 + 0x14),
                    *(undefined1 **)(param_2 + 0xc) == &dhx_asn1_meth);
  return;
}

