%% Péndulo doble invertido sobre carro
% Autor : Andrés Morales Martínez
% Fecha : 20 de Mayo de 2026
% Descripción:
% Parámetros físicos y condiciones iniciales
% del modelo dinámico.

clear; clc;

%% ============================================================
% Parámetros físicos
% =============================================================

g = 9.81; % [m/s^2] Aceleración gravitacional

% Carro
m_c = 10.0; % [kg] Masa del carro

% Primer péndulo
m_1 = 3.0; % [kg] Masa
l_1 = 2.0; % [m] Longitud

% Segundo péndulo
m_2 = 3.0; % [kg] Masa
l_2 = 2.0; % [m] Longitud


%% ============================================================
% Condiciones iniciales
% Vector de estado:
% x = [x_c, dx_c, theta_1, dtheta_1, theta_2, dtheta_2]
% =============================================================

% Carro
x_c0  = 0.0; % [m] Posición
dx_c0 = 0.0; % [m/s] Velocidad

% Primer péndulo
theta_10  = 0.0; % [rad] Ángulo
dtheta_10 = 0.0; % [rad/s] Velocidad angular

% Segundo péndulo
theta_20  = 0.0; % [rad] Ángulo
dtheta_20 = 0.0; % [rad/s] Velocidad angular


%% ============================================================
% Vector de condiciones iniciales
% =============================================================

x0 = [
    x_c0;
    dx_c0;
    theta_10;
    dtheta_10;
    theta_20;
    dtheta_20
];