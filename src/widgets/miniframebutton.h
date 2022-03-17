#ifndef MINIFRAMEBUTTON_H
#define MINIFRAMEBUTTON_H

#include <QPushButton>

#include <DGuiApplicationHelper>

DGUI_USE_NAMESPACE

class MiniFrameButton : public QPushButton
{
    Q_OBJECT

public:
    explicit MiniFrameButton(const QString &text, QWidget *parent = nullptr);

signals:
    void entered() const;

public slots:
    void onThemeTypeChanged(DGuiApplicationHelper::ColorType themeType);

protected:
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
    bool event(QEvent *event) override;

private:
    void updateFont();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QColor m_color;
    QString m_text;
};

#endif
