%% Taller 2: Control de Doble Péndulo Invertido
%
% Este script contiene todos los parámetros necesarios para ejecutar
% la simulación en Simulink.
%
% Notas importantes:
%   1. Para realizar la linealización es necesario definir previamente
%      el punto de operación.
%
%   2. Las matrices del sistema lineal se obtienen a partir del Jacobiano
%      del modelo no lineal derivado mediante Euler-Lagrange.
%
%   3. Antes de calcular la linealización, debe ejecutarse:
%
%           modelado_lagrange.slx
%
%      para generar los campos f y g de la dinámica no lineal.
%
%   4. El modelo Euler-Lagrange implementado en Simulink utiliza las
%      expresiones simbólicas generadas por el archivo anterior. Si se
%      modifica el modelo, dichas expresiones deben actualizarse.
%
% Autor: Andrés Morales Martínez
% -------------------------------------------------------------------------

clear; clc; close all;

show_comparisson = true; 

%% Paths
addpath("matlab/")
addpath("matlab/simulink/")
addpath("results/")
addpath("material/")
addpath("models/")

%% Physical Parameters

Mc = 5.5;      % Cart mass [kg]
m1 = 3.0;      % Pendulum 1 mass [kg]
m2 = 3.3;      % Pendulum 2 mass [kg]

l1 = 0.42;     % Pendulum 1 length [m]
l2 = 0.191;    % Pendulum 2 length [m]

g  = 9.8;      % Gravity [m/s²]

%% Parameter Structure

parameters = struct( ...
    'Mc', Mc, ...
    'm1', m1, ...
    'm2', m2, ...
    'l1', l1, ...
    'l2', l2, ...
    'g',  g );

%% Initial Conditions

% Cart
xc_0  = 1;         % Position [m]
dxc_0 = 0.3;         % Velocity [m/s]

% Pendulum 1
th1_0  = 0.01;   % Angle [rad]
dth1_0 = -0.02;        % Angular velocity [rad/s]

% Pendulum 2
th2_0  = -0.01;         % Angle [rad]
dth2_0 = 0.07;         % Angular velocity [rad/s]

% State vector
x_0 = [ ...
    xc_0;
    dxc_0;
    th1_0;
    dth1_0;
    th2_0;
    dth2_0 ];

%% Linearization Operating Point

x_op = [ ...
    0;      % xc
    0;      % dxc
    0;     % th1
    0;      % dth1
    0;     % th2
    0 ];    % dth2

%% Linear State-Space Model

[A, B] = get_lin_system( ...
    x_op', ...
    Mc, m1, m2, ...
    l1, l2, g);

clc;
disp("- Linearized state-space model generated.")
disp("  Verify that the operating point corresponds to the upright equilibrium.")

%% Salida diff plana 
run diff_flatness.mlx

%% simulación 
simdata = sim("flatness_control_linear_model_inverted_pendulum.slx")
%%
data = simdata.simout.Data; 

t = simdata.simout.Time; 
tau = data(:, 1); 
xc = data(:, 2); 
theta1 = data(:, 3); 
theta2 = data(:, 4); 

hfig = figure;

subplot(3,1,1);
plot(t, tau);
title("Acción de control");
ylabel("Fuerza [N]");
xlabel("tiempo [s]");
ieee_plot(gca)

subplot(3,1,2);
plot(t, xc);
title("Posición del carro");
xlabel("tiempo [s]");
ylabel("$x_c$ [m]");
ieee_plot(gca)

subplot(3,1,3);
plot(t, rad2deg(theta1), t, rad2deg(theta2));
title("Posición angular de los péndulos");
xlabel("tiempo [s]");
ylabel("Posición angular [deg]");
ieee_plot(gca)

% Exportar la figura completa, al margen de ieee_plot
exportgraphics(hfig, "control_case_1.pdf", 'ContentType', 'vector');

%% Casos 
%% ===== Casos de condiciones iniciales =====
% Cada fila: [xc, dxc, th1, dth1, th2, dth2]
casos = [ ...
   -1,   0.01, -0.01,  0.03,  0.04, -0.02;   % Caso 2
    3,  -0.1,  0.04, -0.05, -0.01,  0.03;   % Caso 3
    4,   0.01, -0.04,  0.05,  0.03, -0.01 ]; % Caso 4

nCasos = size(casos, 1);

%% Linearization Operating Point (común a todos los casos)
x_op = [0; 0; 0; 0; 0; 0];   % xc dxc th1 dth1 th2 dth2

[A, B] = get_lin_system(x_op', Mc, m1, m2, l1, l2, g);
clc;
disp("- Linearized state-space model generated.")
disp("  Verify that the operating point corresponds to the upright equilibrium.")

%% Salida diff plana
run diff_flatness.mlx

%% ===== Bucle de simulación por caso =====
for k = 1:nCasos
    % --- Condiciones iniciales del caso k ---
    xc_0   = casos(k, 1);
    dxc_0  = casos(k, 2);
    th1_0  = casos(k, 3);
    dth1_0 = casos(k, 4);
    th2_0  = casos(k, 5);
    dth2_0 = casos(k, 6);

    x_0 = [xc_0; dxc_0; th1_0; dth1_0; th2_0; dth2_0]; %#ok<NASGU>

    % --- Simulación ---
    simdata = sim("flatness_control_linear_model_inverted_pendulum.slx");

    data   = simdata.simout.Data;
    t      = simdata.simout.Time;
    tau    = data(:, 1);
    xc     = data(:, 2);
    theta1 = data(:, 3);
    theta2 = data(:, 4);

    % --- Figura con 3 subplots ---
    hfig = figure;

    subplot(3,1,1);
    plot(t, tau);
    title("Acción de control");
    ylabel("Fuerza [N]");
    xlabel("tiempo [s]");
    ieee_plot(gca)

    subplot(3,1,2);
    plot(t, xc);
    title("Posición del carro");
    xlabel("tiempo [s]");
    ylabel("$x_c$ [m]");
    ieee_plot(gca)

    subplot(3,1,3);
    plot(t, rad2deg(theta1), t, rad2deg(theta2));
    title("Posición angular de los péndulos");
    xlabel("tiempo [s]");
    ylabel("Posición angular [deg]");
    legend("$\theta_1$", "$\theta_2$", 'Interpreter', 'latex');
    ieee_plot(gca)

    % --- Exportar la figura completa de este caso ---
    nombreArchivo = sprintf("control_case_%d.pdf", k);
    exportgraphics(hfig, nombreArchivo, 'ContentType', 'vector');
end

%% ===== Generar tabla LaTeX con el resumen de casos =====
fid = fopen("tabla_casos.tex", "w");
fprintf(fid, "\\begin{table}[H]\n");
fprintf(fid, "\\centering\n");
fprintf(fid, "\\caption{Condiciones iniciales para cada caso de simulación.}\n");
fprintf(fid, "\\label{tab:casos}\n");
fprintf(fid, "\\begin{tabular}{ccccccc}\n");
fprintf(fid, "\\toprule\n");
fprintf(fid, "Caso & $x_c$ [m] & $\\dot{x}_c$ [m/s] & $\\theta_1$ [rad] & $\\dot{\\theta}_1$ [rad/s] & $\\theta_2$ [rad] & $\\dot{\\theta}_2$ [rad/s] \\\\\n");
fprintf(fid, "\\midrule\n");
for k = 1:nCasos
    fprintf(fid, "%d & %.2f & %.2f & %.2f & %.2f & %.2f & %.2f \\\\\n", ...
        k, casos(k,1), casos(k,2), casos(k,3), casos(k,4), casos(k,5), casos(k,6));
end
fprintf(fid, "\\bottomrule\n");
fprintf(fid, "\\end{tabular}\n");
fprintf(fid, "\\end{table}\n");
fclose(fid);

disp("- Tabla LaTeX generada en tabla_casos.tex");