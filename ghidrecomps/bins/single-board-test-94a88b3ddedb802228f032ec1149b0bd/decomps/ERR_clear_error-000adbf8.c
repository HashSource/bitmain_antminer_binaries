
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ERR_clear_error(void)

{
  ERR_STATE *pEVar1;
  char *pcVar2;
  
  pEVar1 = ERR_get_state();
  pEVar1->err_flags[0] = 0;
  pEVar1->err_buffer[0] = 0;
  if ((pEVar1->err_data[0] != (char *)0x0) && (pEVar1->err_data_flags[0] << 0x1f < 0)) {
    CRYPTO_free(pEVar1->err_data[0]);
    pEVar1->err_data[0] = (char *)0x0;
  }
  pcVar2 = pEVar1->err_data[1];
  pEVar1->err_data_flags[0] = 0;
  pEVar1->err_file[0] = (char *)0x0;
  pEVar1->err_flags[1] = 0;
  pEVar1->err_buffer[1] = 0;
  pEVar1->err_line[0] = -1;
  if ((pcVar2 != (char *)0x0) && (pEVar1->err_data_flags[1] << 0x1f < 0)) {
    CRYPTO_free(pcVar2);
    pEVar1->err_data[1] = (char *)0x0;
  }
  pcVar2 = pEVar1->err_data[2];
  pEVar1->err_data_flags[1] = 0;
  pEVar1->err_file[1] = (char *)0x0;
  pEVar1->err_flags[2] = 0;
  pEVar1->err_buffer[2] = 0;
  pEVar1->err_line[1] = -1;
  if ((pcVar2 != (char *)0x0) && (pEVar1->err_data_flags[2] << 0x1f < 0)) {
    CRYPTO_free(pcVar2);
    pEVar1->err_data[2] = (char *)0x0;
  }
  pcVar2 = pEVar1->err_data[3];
  pEVar1->err_data_flags[2] = 0;
  pEVar1->err_file[2] = (char *)0x0;
  pEVar1->err_flags[3] = 0;
  pEVar1->err_buffer[3] = 0;
  pEVar1->err_line[2] = -1;
  if ((pcVar2 != (char *)0x0) && (pEVar1->err_data_flags[3] << 0x1f < 0)) {
    CRYPTO_free(pcVar2);
    pEVar1->err_data[3] = (char *)0x0;
  }
  pcVar2 = pEVar1->err_data[4];
  pEVar1->err_data_flags[3] = 0;
  pEVar1->err_file[3] = (char *)0x0;
  pEVar1->err_flags[4] = 0;
  pEVar1->err_buffer[4] = 0;
  pEVar1->err_line[3] = -1;
  if ((pcVar2 != (char *)0x0) && (pEVar1->err_data_flags[4] << 0x1f < 0)) {
    CRYPTO_free(pcVar2);
    pEVar1->err_data[4] = (char *)0x0;
  }
  pcVar2 = pEVar1->err_data[5];
  pEVar1->err_data_flags[4] = 0;
  pEVar1->err_file[4] = (char *)0x0;
  pEVar1->err_flags[5] = 0;
  pEVar1->err_buffer[5] = 0;
  pEVar1->err_line[4] = -1;
  if ((pcVar2 != (char *)0x0) && (pEVar1->err_data_flags[5] << 0x1f < 0)) {
    CRYPTO_free(pcVar2);
    pEVar1->err_data[5] = (char *)0x0;
  }
  pcVar2 = pEVar1->err_data[6];
  pEVar1->err_data_flags[5] = 0;
  pEVar1->err_file[5] = (char *)0x0;
  pEVar1->err_flags[6] = 0;
  pEVar1->err_buffer[6] = 0;
  pEVar1->err_line[5] = -1;
  if ((pcVar2 != (char *)0x0) && (pEVar1->err_data_flags[6] << 0x1f < 0)) {
    CRYPTO_free(pcVar2);
    pEVar1->err_data[6] = (char *)0x0;
  }
  pcVar2 = pEVar1->err_data[7];
  pEVar1->err_data_flags[6] = 0;
  pEVar1->err_file[6] = (char *)0x0;
  pEVar1->err_flags[7] = 0;
  pEVar1->err_buffer[7] = 0;
  pEVar1->err_line[6] = -1;
  if ((pcVar2 != (char *)0x0) && (pEVar1->err_data_flags[7] << 0x1f < 0)) {
    CRYPTO_free(pcVar2);
    pEVar1->err_data[7] = (char *)0x0;
  }
  pcVar2 = pEVar1->err_data[8];
  pEVar1->err_data_flags[7] = 0;
  pEVar1->err_file[7] = (char *)0x0;
  pEVar1->err_flags[8] = 0;
  pEVar1->err_buffer[8] = 0;
  pEVar1->err_line[7] = -1;
  if ((pcVar2 != (char *)0x0) && (pEVar1->err_data_flags[8] << 0x1f < 0)) {
    CRYPTO_free(pcVar2);
    pEVar1->err_data[8] = (char *)0x0;
  }
  pcVar2 = pEVar1->err_data[9];
  pEVar1->err_data_flags[8] = 0;
  pEVar1->err_file[8] = (char *)0x0;
  pEVar1->err_flags[9] = 0;
  pEVar1->err_buffer[9] = 0;
  pEVar1->err_line[8] = -1;
  if ((pcVar2 != (char *)0x0) && (pEVar1->err_data_flags[9] << 0x1f < 0)) {
    CRYPTO_free(pcVar2);
    pEVar1->err_data[9] = (char *)0x0;
  }
  pcVar2 = pEVar1->err_data[10];
  pEVar1->err_data_flags[9] = 0;
  pEVar1->err_file[9] = (char *)0x0;
  pEVar1->err_flags[10] = 0;
  pEVar1->err_buffer[10] = 0;
  pEVar1->err_line[9] = -1;
  if ((pcVar2 != (char *)0x0) && (pEVar1->err_data_flags[10] << 0x1f < 0)) {
    CRYPTO_free(pcVar2);
    pEVar1->err_data[10] = (char *)0x0;
  }
  pcVar2 = pEVar1->err_data[0xb];
  pEVar1->err_data_flags[10] = 0;
  pEVar1->err_file[10] = (char *)0x0;
  pEVar1->err_flags[0xb] = 0;
  pEVar1->err_buffer[0xb] = 0;
  pEVar1->err_line[10] = -1;
  if ((pcVar2 != (char *)0x0) && (pEVar1->err_data_flags[0xb] << 0x1f < 0)) {
    CRYPTO_free(pcVar2);
    pEVar1->err_data[0xb] = (char *)0x0;
  }
  pcVar2 = pEVar1->err_data[0xc];
  pEVar1->err_data_flags[0xb] = 0;
  pEVar1->err_file[0xb] = (char *)0x0;
  pEVar1->err_flags[0xc] = 0;
  pEVar1->err_buffer[0xc] = 0;
  pEVar1->err_line[0xb] = -1;
  if ((pcVar2 != (char *)0x0) && (pEVar1->err_data_flags[0xc] << 0x1f < 0)) {
    CRYPTO_free(pcVar2);
    pEVar1->err_data[0xc] = (char *)0x0;
  }
  pcVar2 = pEVar1->err_data[0xd];
  pEVar1->err_data_flags[0xc] = 0;
  pEVar1->err_file[0xc] = (char *)0x0;
  pEVar1->err_flags[0xd] = 0;
  pEVar1->err_buffer[0xd] = 0;
  pEVar1->err_line[0xc] = -1;
  if ((pcVar2 != (char *)0x0) && (pEVar1->err_data_flags[0xd] << 0x1f < 0)) {
    CRYPTO_free(pcVar2);
    pEVar1->err_data[0xd] = (char *)0x0;
  }
  pcVar2 = pEVar1->err_data[0xe];
  pEVar1->err_data_flags[0xd] = 0;
  pEVar1->err_file[0xd] = (char *)0x0;
  pEVar1->err_flags[0xe] = 0;
  pEVar1->err_buffer[0xe] = 0;
  pEVar1->err_line[0xd] = -1;
  if ((pcVar2 != (char *)0x0) && (pEVar1->err_data_flags[0xe] << 0x1f < 0)) {
    CRYPTO_free(pcVar2);
    pEVar1->err_data[0xe] = (char *)0x0;
  }
  pcVar2 = pEVar1->err_data[0xf];
  pEVar1->err_data_flags[0xe] = 0;
  pEVar1->err_file[0xe] = (char *)0x0;
  pEVar1->err_flags[0xf] = 0;
  pEVar1->err_buffer[0xf] = 0;
  pEVar1->err_line[0xe] = -1;
  if ((pcVar2 != (char *)0x0) && (pEVar1->err_data_flags[0xf] << 0x1f < 0)) {
    CRYPTO_free(pcVar2);
    pEVar1->err_data[0xf] = (char *)0x0;
  }
  pEVar1->err_data_flags[0xf] = 0;
  pEVar1->err_file[0xf] = (char *)0x0;
  pEVar1->bottom = 0;
  pEVar1->top = 0;
  pEVar1->err_line[0xf] = -1;
  return;
}

