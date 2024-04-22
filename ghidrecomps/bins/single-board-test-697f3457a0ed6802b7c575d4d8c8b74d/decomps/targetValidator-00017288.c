
uint32_t targetValidator(uint8_t *work,uint8_t *nonce,uint8_t *target)

{
  undefined2 uVar1;
  uint8_t uVar2;
  uint32_t uVar3;
  uint8_t *target_local;
  uint8_t *nonce_local;
  uint8_t *work_local;
  uint8_t output [32];
  uint8_t tmphash [32];
  uint8_t input [1487];
  uint8_t str [3];
  
  uVar2 = DAT_0003497a;
  uVar1 = DAT_00034978;
  memset(input,0,0x5cf);
  memset(tmphash,0,0x20);
  memset(output,0,0x20);
  memcpy(input,work,0x8c);
  input._140_2_ = uVar1;
  input[142] = uVar2;
  memcpy(input + 0x8f,nonce,0x540);
  Sha256_Onestep(input,0x5cf,tmphash);
  Sha256_Onestep(tmphash,0x20,output);
  *(undefined4 *)target = output._0_4_;
  *(undefined4 *)(target + 4) = output._4_4_;
  *(undefined4 *)(target + 8) = output._8_4_;
  *(undefined4 *)(target + 0xc) = output._12_4_;
  *(undefined4 *)(target + 0x10) = output._16_4_;
  *(undefined4 *)(target + 0x14) = output._20_4_;
  *(undefined4 *)(target + 0x18) = output._24_4_;
  *(undefined4 *)(target + 0x1c) = output._28_4_;
  uVar3 = target_zero_cal(output);
  return uVar3;
}

