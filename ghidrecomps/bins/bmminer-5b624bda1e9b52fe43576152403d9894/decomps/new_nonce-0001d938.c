
/* WARNING: Unknown calling convention */

_Bool new_nonce(thr_info *thr,uint nonce)

{
  undefined uVar1;
  cgpu_info *pcVar2;
  cgpu_info *cgpu;
  bool bVar3;
  char tmp42 [2048];
  
  pcVar2 = thr->cgpu;
  bVar3 = pcVar2->last_nonce == nonce;
  if (!bVar3) {
    pcVar2->last_nonce = nonce;
    thr = (thr_info *)0x1;
  }
  uVar1 = SUB41(thr,0);
  if ((bVar3) &&
     (((*DAT_0001d990 != '\0' || (*DAT_0001d994 != '\0')) || (uVar1 = 0, 5 < *DAT_0001d998)))) {
    snprintf(tmp42,0x800,DAT_0001d99c,pcVar2->drv->name,pcVar2->device_id);
    _applog(6,tmp42,false);
    uVar1 = 0;
  }
  return (_Bool)uVar1;
}

