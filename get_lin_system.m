function [A, B] = get_lin_system(x_op, Mc_v, m1_v, m2_v, l1_v, l2_v, g_v)
% GET LIN SYSTEM
% -
% Get the linealization matrices of the non-linear system 
% By means of the Jacobian 

load("vector_fields.mat", "f_field", "g_field"); 

syms Mc m1 m2 l1 l2 th1 dth1 th2 dth2 xc dxc g tau 

x = [xc, dxc, th1, dth1, th2, dth2]; 
A_lin = jacobian(f_field, x); 
B_lin = jacobian(g_field, tau); 

xc_v = x_op(1); 
dxc_v = x_op(2); 
th1_v = x_op(3); 
dth1_v = x_op(4); 
th2_v = x_op(5); 
dth2_v = x_op(6); 

% Matrices de linealizzación 
A = double(subs(A_lin, [th1, dth1, th2, dth2, xc, dxc, Mc, m1, m2, l1, l2, g], [th1_v, dth1_v, th2_v, dth2_v, xc_v, dxc_v, Mc_v, m1_v, m2_v, l1_v, l2_v, g_v]));
B = double(subs(B_lin, [th1, dth1, th2, dth2, xc, dxc, Mc, m1, m2, l1, l2, g], [th1_v, dth1_v, th2_v, dth2_v, xc_v, dxc_v, Mc_v, m1_v, m2_v, l1_v, l2_v, g_v])); 
end