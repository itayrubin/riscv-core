module alu (
	input wire [31:0] a,
	input wire [31:0] b,
	input wire [2:0] op,
	output reg [31:0] result
);
	localparam OP_ADD = 3'b000;
	localparam OP_SUB = 3'b001;
	localparam OP_AND = 3'b010;
	localparam OP_OR = 3'b011;
	localparam OP_XOR = 3'b100;
	localparam OP_SLL = 3'b101;
	localparam OP_SRL = 3'b110;
	localparam OP_SLT = 3'b111;

	always @(*) begin
		case (op)
			OP_ADD: result = a + b;
			OP_SUB: result = a - b;
			OP_AND: result = a & b;
			OP_OR: result = a | b;
			OP_XOR: result = a ^ b;
			OP_SLL: result = a << b[4:0];
			OP_SRL: result = a >> b[4:0];
			OP_SLT: result = ($signed(a) < $signed(b)) ? 32'd1 : 32'd0;
			default: result = 32'd0;
		endcase
	end
endmodule
