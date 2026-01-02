# Put 64 bit constant 0xFEDCBA9876543210 to t0
# This algorithm can work with arbitrary values (signed or unsigned)
# Uses t0, t1 and t2

start:
	# Load high 32 bits (sign independent)
	lui     t0, 0xFEDCB
	lui     t1, 0xA98
	srli	t1, t1, 12 
	or	t0, t0, t1
	slli    t0, t0, 32

	# Load low 32 bits (sign independent)
	lui     t2, 0x76543
	lui     t1, 0x210
	srli	t1, t1, 12 
	or	t2, t2, t1

	# Clear high 32 bits in t2
	slli     t2, t2,32
	srli     t2, t2,32

	# Combine the two parts
	or	t0, t0, t2 

	# Exit
	ret
