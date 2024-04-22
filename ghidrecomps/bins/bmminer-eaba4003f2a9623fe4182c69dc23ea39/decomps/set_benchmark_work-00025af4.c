
void set_benchmark_work(cgpu_info *cgpu,work *work)

{
  work *work_local;
  cgpu_info *cgpu_local;
  
  cgpu->lodiff = cgpu->lodiff + cgpu->direction;
  if (cgpu->lodiff < 1) {
    cgpu->direction = 1;
  }
  if (cgpu->lodiff < 0x10) {
    _cg_memcpy(work,bench_lodiff_bins + cgpu->lodiff,0xa0,"cgminer.c","set_benchmark_work",0x2140);
  }
  else {
    cgpu->direction = -1;
    cgpu->hidiff = cgpu->hidiff + 1;
    if (0xf < cgpu->hidiff) {
      cgpu->hidiff = 0;
    }
    _cg_memcpy(work,bench_hidiff_bins + cgpu->hidiff,0xa0,"cgminer.c","set_benchmark_work",0x213c);
  }
  return;
}

