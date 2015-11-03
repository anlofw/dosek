// See LICENSE for license details.

#ifndef RISCV_CSR_ENCODING_H
#define RISCV_CSR_ENCODING_H

#define MSTATUS_IE          0x00000001
#define MSTATUS_PRV         0x00000006
#define MSTATUS_IE1         0x00000008
#define MSTATUS_PRV1        0x00000030
#define MSTATUS_IE2         0x00000040
#define MSTATUS_PRV2        0x00000180
#define MSTATUS_IE3         0x00000200
#define MSTATUS_PRV3        0x00000C00
#define MSTATUS_FS          0x00003000
#define MSTATUS_XS          0x0000C000
#define MSTATUS_MPRV        0x00010000
#define MSTATUS_VM          0x003E0000
#define MSTATUS32_SD        0x80000000
#define MSTATUS64_SD        0x8000000000000000

#define SSTATUS_IE          0x00000001
#define SSTATUS_PIE         0x00000008
#define SSTATUS_PS          0x00000010
#define SSTATUS_FS          0x00003000
#define SSTATUS_XS          0x0000C000
#define SSTATUS_MPRV        0x00010000
#define SSTATUS_TIE         0x01000000
#define SSTATUS32_SD        0x80000000
#define SSTATUS64_SD        0x8000000000000000

#define MIP_SSIP            0x00000002
#define MIP_HSIP            0x00000004
#define MIP_MSIP            0x00000008
#define MIP_STIP            0x00000020
#define MIP_HTIP            0x00000040
#define MIP_MTIP            0x00000080

#define SIP_SSIP MIP_SSIP
#define SIP_STIP MIP_STIP

#define PRV_U 0
#define PRV_S 1
#define PRV_H 2
#define PRV_M 3

#define VM_MBARE 0
#define VM_MBB   1
#define VM_MBBID 2
#define VM_SV32  8
#define VM_SV39  9
#define VM_SV48  10

#define UA_RV32  0
#define UA_RV64  4
#define UA_RV128 8

#define IRQ_SOFT   0
#define IRQ_TIMER  1
#define IRQ_HOST   2
#define IRQ_COP    3

#define IMPL_ROCKET 1

#define DEFAULT_MTVEC 0x100

#define CSR_FFLAGS 0x1
#define CSR_FRM 0x2
#define CSR_FCSR 0x3
#define CSR_CYCLE 0xc00
#define CSR_TIME 0xc01
#define CSR_INSTRET 0xc02
#define CSR_STATS 0xc0
#define CSR_UARCH0 0xcc0
#define CSR_UARCH1 0xcc1
#define CSR_UARCH2 0xcc2
#define CSR_UARCH3 0xcc3
#define CSR_UARCH4 0xcc4
#define CSR_UARCH5 0xcc5
#define CSR_UARCH6 0xcc6
#define CSR_UARCH7 0xcc7
#define CSR_UARCH8 0xcc8
#define CSR_UARCH9 0xcc9
#define CSR_UARCH10 0xcca
#define CSR_UARCH11 0xccb
#define CSR_UARCH12 0xccc
#define CSR_UARCH13 0xccd
#define CSR_UARCH14 0xcce
#define CSR_UARCH15 0xccf
#define CSR_SSTATUS 0x100
#define CSR_STVEC 0x101
#define CSR_SIE 0x104
#define CSR_SSCRATCH 0x140
#define CSR_SEPC 0x141
#define CSR_SIP 0x144
#define CSR_SPTBR 0x180
#define CSR_SASID 0x181
#define CSR_CYCLEW 0x900
#define CSR_TIMEW 0x901
#define CSR_INSTRETW 0x902
#define CSR_STIME 0xd01
#define CSR_SCAUSE 0xd42
#define CSR_SBADADDR 0xd43
#define CSR_STIMEW 0xa01
#define CSR_MSTATUS 0x300
#define CSR_MTVEC 0x301
#define CSR_MTDELEG 0x302
#define CSR_MIE 0x304
#define CSR_MTIMECMP 0x321
#define CSR_MSCRATCH 0x340
#define CSR_MEPC 0x341
#define CSR_MCAUSE 0x342
#define CSR_MBADADDR 0x343
#define CSR_MIP 0x344
#define CSR_MTIME 0x701
#define CSR_MCPUID 0xf00
#define CSR_MIMPID 0xf01
#define CSR_MHARTID 0xf10
#define CSR_MTOHOST 0x780
#define CSR_MFROMHOST 0x781
#define CSR_MRESET 0x782
#define CSR_SEND_IPI 0x783
#define CSR_CYCLEH 0xc80
#define CSR_TIMEH 0xc81
#define CSR_INSTRETH 0xc82
#define CSR_CYCLEHW 0x980
#define CSR_TIMEHW 0x981
#define CSR_INSTRETHW 0x982
#define CSR_STIMEH 0xd81
#define CSR_STIMEHW 0xa81
#define CSR_MTIMECMPH 0x361
#define CSR_MTIMEH 0x741
#define CAUSE_MISALIGNED_FETCH 0x0
#define CAUSE_FAULT_FETCH 0x1
#define CAUSE_ILLEGAL_INSTRUCTION 0x2
#define CAUSE_BREAKPOINT 0x3
#define CAUSE_MISALIGNED_LOAD 0x4
#define CAUSE_FAULT_LOAD 0x5
#define CAUSE_MISALIGNED_STORE 0x6
#define CAUSE_FAULT_STORE 0x7
#define CAUSE_USER_ECALL 0x8
#define CAUSE_SUPERVISOR_ECALL 0x9
#define CAUSE_HYPERVISOR_ECALL 0xa
#define CAUSE_MACHINE_ECALL 0xb

#define DECLARE_CSR(name, val) enum{ name = val};

DECLARE_CSR(fflags, CSR_FFLAGS)
DECLARE_CSR(frm, CSR_FRM)
DECLARE_CSR(fcsr, CSR_FCSR)
DECLARE_CSR(cycle, CSR_CYCLE)
DECLARE_CSR(time, CSR_TIME)
DECLARE_CSR(instret, CSR_INSTRET)
DECLARE_CSR(stats, CSR_STATS)
DECLARE_CSR(uarch0, CSR_UARCH0)
DECLARE_CSR(uarch1, CSR_UARCH1)
DECLARE_CSR(uarch2, CSR_UARCH2)
DECLARE_CSR(uarch3, CSR_UARCH3)
DECLARE_CSR(uarch4, CSR_UARCH4)
DECLARE_CSR(uarch5, CSR_UARCH5)
DECLARE_CSR(uarch6, CSR_UARCH6)
DECLARE_CSR(uarch7, CSR_UARCH7)
DECLARE_CSR(uarch8, CSR_UARCH8)
DECLARE_CSR(uarch9, CSR_UARCH9)
DECLARE_CSR(uarch10, CSR_UARCH10)
DECLARE_CSR(uarch11, CSR_UARCH11)
DECLARE_CSR(uarch12, CSR_UARCH12)
DECLARE_CSR(uarch13, CSR_UARCH13)
DECLARE_CSR(uarch14, CSR_UARCH14)
DECLARE_CSR(uarch15, CSR_UARCH15)
DECLARE_CSR(sstatus, CSR_SSTATUS)
DECLARE_CSR(stvec, CSR_STVEC)
DECLARE_CSR(sie, CSR_SIE)
DECLARE_CSR(sscratch, CSR_SSCRATCH)
DECLARE_CSR(sepc, CSR_SEPC)
DECLARE_CSR(sip, CSR_SIP)
DECLARE_CSR(sptbr, CSR_SPTBR)
DECLARE_CSR(sasid, CSR_SASID)
DECLARE_CSR(cyclew, CSR_CYCLEW)
DECLARE_CSR(timew, CSR_TIMEW)
DECLARE_CSR(instretw, CSR_INSTRETW)
DECLARE_CSR(stime, CSR_STIME)
DECLARE_CSR(scause, CSR_SCAUSE)
DECLARE_CSR(sbadaddr, CSR_SBADADDR)
DECLARE_CSR(stimew, CSR_STIMEW)
DECLARE_CSR(mstatus, CSR_MSTATUS)
DECLARE_CSR(mtvec, CSR_MTVEC)
DECLARE_CSR(mtdeleg, CSR_MTDELEG)
DECLARE_CSR(mie, CSR_MIE)
DECLARE_CSR(mtimecmp, CSR_MTIMECMP)
DECLARE_CSR(mscratch, CSR_MSCRATCH)
DECLARE_CSR(mepc, CSR_MEPC)
DECLARE_CSR(mcause, CSR_MCAUSE)
DECLARE_CSR(mbadaddr, CSR_MBADADDR)
DECLARE_CSR(mip, CSR_MIP)
DECLARE_CSR(mtime, CSR_MTIME)
DECLARE_CSR(mcpuid, CSR_MCPUID)
DECLARE_CSR(mimpid, CSR_MIMPID)
DECLARE_CSR(mhartid, CSR_MHARTID)
DECLARE_CSR(mtohost, CSR_MTOHOST)
DECLARE_CSR(mfromhost, CSR_MFROMHOST)
DECLARE_CSR(mreset, CSR_MRESET)
DECLARE_CSR(send_ipi, CSR_SEND_IPI)
DECLARE_CSR(cycleh, CSR_CYCLEH)
DECLARE_CSR(timeh, CSR_TIMEH)
DECLARE_CSR(instreth, CSR_INSTRETH)
DECLARE_CSR(cyclehw, CSR_CYCLEHW)
DECLARE_CSR(timehw, CSR_TIMEHW)
DECLARE_CSR(instrethw, CSR_INSTRETHW)
DECLARE_CSR(stimeh, CSR_STIMEH)
DECLARE_CSR(stimehw, CSR_STIMEHW)
DECLARE_CSR(mtimecmph, CSR_MTIMECMPH)
DECLARE_CSR(mtimeh, CSR_MTIMEH)
#endif