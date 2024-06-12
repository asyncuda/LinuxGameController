config = {
    path = "/dev/input/by-id/usb-Logicool_Gamepad_F310_DA822D76-joystick";
}

function DeviceActive()
    print("UNDERTALE !!!");
end

function DeviceDeactive()

end

function AxisOnEvent(number, value)

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
            PressButton(KEY_Z());
        end
        if(value == 0) then
            ReleaseButton(KEY_Z());
        end
    end

    if(number == 1) then
        if(value == 1) then
            PressButton(KEY_X());
        end
        if(value == 0) then
            ReleaseButton(KEY_X());
        end
    end

    if(number == 2) then
        if(value == 1) then
            PressButton(KEY_C());
        end
        if(value == 0) then
            ReleaseButton(KEY_C());
        end
    end

end
