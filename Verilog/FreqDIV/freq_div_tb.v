
module freq_div_tb();

	reg	clk_in;
	reg	clk_out;
	reg	n_rst;

	integer step;

	initial
	begin
		`ifdef __ICARUS__
			$dumpvars;
		`endif

		// Reset cycle
		n_rst = 1'b0;
                # (10);
                n_rst = 1'b1;
                # (10);


		for(step = 0; step < 32; step = step + 1)
                begin
			clk_in = 1'b0;
			$display("@%0t: clk_in = %b, clk_out = %b", $time, clk_in, clk_out);
                	# (10);

			clk_in = 1'b1;
			$display("@%0t: clk_in = %b, clk_out = %b", $time, clk_in, clk_out);
                	# (10);
			
		end
	
	end

	frquency_divider_by2 dut(.clk_in(clk_in), .clk_out(clk_out), .n_rst(n_rst));

endmodule
