freq_div_tb: freq_div_tb.vvp
	vvp freq_div_tb.vvp

freq_div_tb.vvp: freq_div_tb.v freq_div.v
	iverilog -g2005-sv -s freq_div_tb -o freq_div_tb.vvp freq_div_tb.v freq_div.v

clean:
	rm freq_div freq_div_tb.vvp dump.vcd


