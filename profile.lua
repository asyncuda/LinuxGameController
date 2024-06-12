config = {
    path = "/dev/input/by-id/usb-Logicool_Gamepad_F310_DA822D76-joystick";
    interval = 8000;
}

local accel = 1;

function DeviceActive()
   print(DeviceName());
end

function DeviceDeactive()
    print("end");
end

function AxisOnEvent(number, value)
 
    if(number == 0) then
        if(value > AXIS_VALUE_MAX() / 4) then
            if(value == AXIS_VALUE_MAX()) then
                MovingCursorX(2*accel);
            else
                MovingCursorX(accel);
            end
        elseif(value < AXIS_VALUE_MIN() / 4) then
            if(value == AXIS_VALUE_MIN()) then
                MovingCursorX(-2*accel);
            else    
                MovingCursorX(-accel);
            end
        else
            StopCursorX();
        end
    end

    if(number == 1) then
        if(value > AXIS_VALUE_MAX() / 4) then
            if(value == AXIS_VALUE_MAX()) then
                MovingCursorY(2*accel);
            else
                MovingCursorY(accel);
            end
        elseif(value < AXIS_VALUE_MIN() / 4) then
            if(value == AXIS_VALUE_MIN()) then
                MovingCursorY(-2*accel);
            else    
                MovingCursorY(-accel);
            end
        else
            StopCursorY();
        end
    end

   if(number == 3) then
        if(value == AXIS_VALUE_MAX()) then
            MouseWheel(1);
        elseif(value == AXIS_VALUE_MIN()) then
            MouseWheel(-1);
        end
    end

    if(number == 4) then
        if(value == AXIS_VALUE_MAX()) then
                MouseWheeling(1);
        elseif(value == AXIS_VALUE_MIN()) then
                MouseWheeling(-1);
        else
            StopWheeling();
        end
    end

    if(number == 2 or number == 5) then
        if(value == AXIS_VALUE_MAX()) then
            accel = 6;
        else
            accel = 1;
        end
        
    end

    if(number == 6) then
        if(value == AXIS_VALUE_MAX()) then
            PressButton(KEY_RIGHT());
        elseif(value == AXIS_VALUE_MIN()) then
            PressButton(KEY_LEFT());
        else
            ReleaseButton(KEY_RIGHT());
            ReleaseButton(KEY_LEFT());
        end
    end
 
    if(number == 7) then
        if(value == AXIS_VALUE_MAX()) then
            PressButton(KEY_DOWN());
        elseif(value == AXIS_VALUE_MIN()) then
            PressButton(KEY_UP());
        else
            ReleaseButton(KEY_DOWN());
            ReleaseButton(KEY_UP());
        end
    end

end

function ButtonOnEvent(number, value)

    if(number == 0) then
        if(value == 1) then
            PressButton(BTN_LEFT());
        end
        if(value == 0) then
            ReleaseButton(BTN_LEFT());
        end
    end

    if(number == 1) then
        if(value == 1) then
            PressButton(BTN_RIGHT());
        end
        if(value == 0) then
            ReleaseButton(BTN_RIGHT());
        end
    end

    if(number == 2) then
        if(value == 1) then
            PressButton(KEY_LEFTALT());
            PressButton(KEY_LEFT());
        end
        if(value == 0) then
            ReleaseButton(KEY_LEFTALT());
            ReleaseButton(KEY_LEFT());
        end
    end

    if(number == 3) then
        if(value == 1) then
            PressButton(KEY_LEFTALT());
            PressButton(KEY_RIGHT());
        end
        if(value == 0) then
            ReleaseButton(KEY_LEFTALT());
            ReleaseButton(KEY_RIGHT());
        end
    end

    if(number == 4) then
        if(value == 1) then
            PressButton(KEY_LEFTCTRL());
            PressButton(KEY_B());
        end
        if(value == 0) then
            ReleaseButton(KEY_LEFTCTRL());
            ReleaseButton(KEY_B());
        end
    end

    if(number == 6) then
        if(value == 1) then
            PressButton(KEY_ESC());
        end
        if(value == 0) then
            ReleaseButton(KEY_ESC());
        end
    end

    if(number == 7) then
        if(value == 1) then
            PressButton(KEY_SUPER());
        end
        if(value == 0) then
            ReleaseButton(KEY_SUPER());
        end
    end
end
