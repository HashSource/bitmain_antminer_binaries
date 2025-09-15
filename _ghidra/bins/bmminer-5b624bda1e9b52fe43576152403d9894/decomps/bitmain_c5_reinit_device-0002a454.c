
/* WARNING: Unknown calling convention */

void bitmain_c5_reinit_device(cgpu_info *bitmain)

{
  if (!status_error) {
    (*(code *)(undefined *)0x0)("/etc/init.d/bmminer.sh restart > /dev/null 2>&1 &");
    return;
  }
  return;
}

