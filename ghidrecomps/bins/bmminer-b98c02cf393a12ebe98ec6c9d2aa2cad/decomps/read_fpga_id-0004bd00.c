
void read_fpga_id(undefined4 param_1)

{
  (*(code *)PTR_sprintf_0007d044)
            (param_1,&UNK_00068a90,*(undefined4 *)(axi_fpga_addr + 0xf4),
             *(undefined4 *)(axi_fpga_addr + 0xf0));
  return;
}

