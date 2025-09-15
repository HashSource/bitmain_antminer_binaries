
void reinit_device(cgpu_info *cgpu)

{
  cgpu_info *cgpu_local;
  
  if (cgpu->deven != DEV_DISABLED) {
    (*cgpu->drv->reinit_device)(cgpu);
  }
  return;
}

