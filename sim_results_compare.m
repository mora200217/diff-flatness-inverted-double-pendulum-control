%% Simulation getter 

data = sim("two_pendulum_model_euler_simscape.slx");

%%
t = data.tout; % simulation time 

% Get each case result
euler_sim = data.euler; 
simscape_sim = data.simscape; 
linear_sim = data.linear; 

%% State vector for each system
% Vector order:
% (xc, dxc, th1, dth1, th2, dth2)

x_euler    = euler_sim.Data;
x_simscape = simscape_sim.Data;
x_linear   = linear_sim.Data;

%% Theta 1 comparison

theta_euler    = x_euler(:,3);
theta_linear   = x_linear(:,3);
theta_simscape = x_simscape(:,3);

%% Error signals (Euler-Lagrange as reference)

err_linear   = theta_linear   - theta_euler;
err_simscape = theta_simscape - theta_euler;

%% Error metrics

rmse_linear   = rms(err_linear);
rmse_simscape = rms(err_simscape);

max_linear   = max(abs(err_linear));
max_simscape = max(abs(err_simscape));

fprintf('\nTheta_1 Validation Metrics\n');
fprintf('----------------------------------------\n');
fprintf('Linear vs Euler-Lagrange:\n');
fprintf('   RMSE      = %.3e rad\n', rmse_linear);
fprintf('   Max Error = %.3e rad\n\n', max_linear);

fprintf('Simscape vs Euler-Lagrange:\n');
fprintf('   RMSE      = %.3e rad\n', rmse_simscape);
fprintf('   Max Error = %.3e rad\n', max_simscape);

%% Plot comparison and errors

figure();

subplot(2,1,1)
plot(t, theta_euler,    'k',  'LineWidth', 2); hold on;
plot(t, theta_linear,   '--b', 'LineWidth', 1.5);
plot(t, theta_simscape, ':r',  'LineWidth', 1.5);

title('\theta_1 Comparison Across Models');
ylabel('\theta_1 [rad]');
legend('Euler-Lagrange','Linear','Simscape', ...
       'Location','best');
grid on;

subplot(2,1,2)
plot(t, err_linear,   'b', 'LineWidth', 1.5); hold on;
plot(t, err_simscape, 'r', 'LineWidth', 1.5);

xlabel('Time [s]');
ylabel('Error [rad]');
title('Deviation from Euler-Lagrange Model');

legend( ...
    sprintf('Linear (RMSE = %.2e)', rmse_linear), ...
    sprintf('Simscape (RMSE = %.2e)', rmse_simscape), ...
    'Location','best');

grid on;
ieee_plot(gca, 'Export', "error_overlap_responses"); 


%% Optional zoomed comparison figure

figure('Color','w');

plot(t, theta_euler,    'k',  'LineWidth', 2); hold on;
plot(t, theta_linear,   '--b', 'LineWidth', 1.5);
plot(t, theta_simscape, ':r',  'LineWidth', 1.5);

xlabel('Time [s]');
ylabel('$\theta_1$ [rad]');
title('$\theta_1$ Comparison (Zoomed View)');
legend('Euler-Lagrange','Linear','Simscape', ...
       'Location','best');

grid on;

% Adjust these limits to a region where differences appear
xlim([1.5 2.5]);


ieee_plot(gca, 'Export', "zoomed_comparisson_responses"); 
