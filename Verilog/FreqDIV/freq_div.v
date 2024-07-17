module frquency_divider_by2 (
	input clk_in,
	output clk_out,
	input n_rst
);
	reg q;

	assign clk_out = q;

	always @ (posedge clk_in or negedge n_rst) begin
		if(!n_rst) begin
			q <= 0;
		end else begin
			q <= ~q;
		end
	end
endmodule
