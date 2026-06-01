function ieee_plot(ax, opts)
% IEEE_PLOT Formatea una figura con estilo profesional tipo IEEE
%
% Uso:
%   plot(t,x); ieee_plot(gca)
%   ieee_plot(gca, 'Column','double', 'Export','fig1')
%
% Opciones (name-value):
%   'Column'      : 'single' (default) | 'double'
%   'Export'      : nombre de archivo, p.ej. 'fig1' -> exporta fig1.pdf
%   'AspectRatio' : relación ancho/alto (default 1.4)

    arguments
        ax = gca
        opts.Column   (1,:) char {mustBeMember(opts.Column,{'single','double'})} = 'double'
        opts.Export   (1,:) char = ''
        opts.AspectRatio (1,1) double = 1.7
    end

    fig = ancestor(ax,'figure');

    % ----- Tamaño físico (columna IEEE) -----
    if strcmp(opts.Column,'single')
        wIn = 3.5;
    else
        wIn = 7.16;
    end
    hIn = wIn / opts.AspectRatio;
    set(fig,'Units','inches','Position',[1 1 wIn hIn], ...
            'Color','w','PaperPositionMode','auto');

    % ----- Fuente -----
    ax.FontName   = 'Times New Roman';
    ax.FontSize   = 8;
    ax.TickLabelInterpreter = 'latex';

    % ----- Ejes: ticks hacia ADENTRO, finos y discretos -----
    ax.LineWidth   = 0.5;
    ax.Box         = 'on';
    ax.TickDir     = 'in';           % <-- adentro, mucho más limpio
    ax.TickLength  = [0.008 0.008];  % <-- ticks cortos
    ax.XColor      = [0.15 0.15 0.15];
    ax.YColor      = [0.15 0.15 0.15];
    ax.Layer       = 'top';
    ax.XMinorTick  = 'off';
    ax.YMinorTick  = 'off';

    % ----- Separar los números de tick de los ejes -----
    ax.XRuler.TickLabelGapOffset = 3;
    ax.YRuler.TickLabelGapOffset = 3;

    % ----- Grid suave -----
    ax.XGrid          = 'on';
    ax.YGrid          = 'on';
    ax.GridLineStyle  = '-';
    ax.GridColor      = [0 0 0];
    ax.GridAlpha      = 0.10;

    % ----- Líneas -----
    palette = [ 0.000 0.447 0.741;
                0.850 0.325 0.098;
                0.929 0.694 0.125;
                0.494 0.184 0.556;
                0.466 0.674 0.188];
    styles  = {'-','--',':','-.'};
    lines = flipud(findobj(ax,'Type','Line'));
    for k = 1:numel(lines)
        lines(k).LineWidth = 1.2;
        ci = mod(k-1,size(palette,1)) + 1;
        si = mod(k-1,numel(styles)) + 1;
        lines(k).Color     = palette(ci,:);
        lines(k).LineStyle = styles{si};
    end

    % ----- Labels y título con LaTeX y BIEN separados de los ejes -----
    ax.XLabel.Interpreter = 'latex';
    ax.YLabel.Interpreter = 'latex';
    ax.Title.Interpreter  = 'latex';
    ax.XLabel.FontSize = 9;
    ax.YLabel.FontSize = 9;
    ax.Title.FontSize  = 10;
    ax.Title.FontWeight = 'normal';

    % separación de los labels respecto al eje (unidades normalizadas)
    ax.XLabel.Units = 'normalized';
    ax.YLabel.Units = 'normalized';
    ax.XLabel.Position(2) = -0.07;   % baja el "Time [s]"
    ax.YLabel.Position(1) = -0.07;   % aleja el label vertical

    % ----- Leyenda CON caja -----
    lgd = get(ax,'Legend');
    if ~isempty(lgd)
        lgd.Interpreter = 'latex';
        lgd.FontName    = 'Times New Roman';
        lgd.FontSize    = 8;
        lgd.Box         = 'on';            % <-- caja
        lgd.EdgeColor   = [0.6 0.6 0.6];
        lgd.Color       = 'w';
        lgd.LineWidth   = 0.5;
        lgd.Location    = 'best';
        lgd.ItemTokenSize = [18 8];
    end

    % ----- Exportar vectorial -----
    if ~isempty(opts.Export)
        exportgraphics(ax,['results/', opts.Export, '.pdf'], ...
            'ContentType','vector','BackgroundColor','white');
    end
end